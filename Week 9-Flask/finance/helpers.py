import csv
import datetime
import pytz
import requests
import subprocess
import urllib
import uuid

from flask import Flask, redirect, render_template, request, session, flash
from functools import wraps

app = Flask(__name__)
app.secret_key = "supersecretkey"  # For session handling (set your secret key)
users_db = {}  # This is an in-memory dictionary simulating user data storage.


def apology(message, code=400):
    """Render message as an apology to user."""
    def escape(s):
        """
        Escape special characters.

        https://github.com/jacebrowning/memegen#special-characters
        """
        for old, new in [("-", "--"), (" ", "-"), ("_", "__"), ("?", "~q"),
                         ("%", "~p"), ("#", "~h"), ("/", "~s"), ("\"", "''")]:
            s = s.replace(old, new)
        return s
    return render_template("apology.html", top=code, bottom=escape(message)), code


def login_required(f):
    """
    Decorate routes to require login.

    http://flask.pocoo.org/docs/0.12/patterns/viewdecorators/
    """
    @wraps(f)
    def decorated_function(*args, **kwargs):
        if session.get("user_id") is None:
            return redirect("/login")
        return f(*args, **kwargs)
    return decorated_function


@app.route("/register", methods=["GET", "POST"])
def register():
    """Handle user registration, check for duplicate usernames."""
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")

        # Check if the username already exists in the "database"
        if username in users_db:
            flash("Username already taken, please choose another one.", "error")
            return redirect("/register")

        # Store the user if the username is available
        users_db[username] = password
        flash("Registration successful!", "success")
        return redirect("/login")

    return render_template("register.html")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Handle user login."""
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")

        # Check if the username exists and password matches
        if users_db.get(username) == password:
            session["user_id"] = username
            return redirect("/")
        else:
            flash("Invalid username or password.", "error")
            return redirect("/login")

    return render_template("login.html")


@app.route("/")
@login_required
def index():
    """Home page for logged-in users."""
    return render_template("index.html")


def lookup(symbol):
    """Look up quote for symbol."""
    symbol = symbol.upper()
    end = datetime.datetime.now(pytz.timezone("US/Eastern"))
    start = end - datetime.timedelta(days=7)

    # Yahoo Finance API
    url = (
        f"https://query1.finance.yahoo.com/v7/finance/download/{urllib.parse.quote_plus(symbol)}"
        f"?period1={int(start.timestamp())}"
        f"&period2={int(end.timestamp())}"
        f"&interval=1d&events=history&includeAdjustedClose=true"
    )

    # Query API
    try:
        response = requests.get(url, cookies={"session": str(uuid.uuid4())}, headers={
                                "User-Agent": "python-requests", "Accept": "*/*"})
        response.raise_for_status()

        # CSV header: Date,Open,High,Low,Close,Adj Close,Volume
        quotes = list(csv.DictReader(response.content.decode("utf-8").splitlines()))
        quotes.reverse()
        price = round(float(quotes[0]["Adj Close"]), 2)
        return {
            "name": symbol,
            "price": price,
            "symbol": symbol
        }
    except (requests.RequestException, ValueError, KeyError, IndexError):
        return None


def usd(value):
    """Format value as USD."""
    return f"${value:,.2f}"


if __name__ == "__main__":
    app.run(debug=True)
