from flask import Flask, render_template

app = Flask(__name__)


@app.route("/")
def homepage():
    """
    Penangan rute untuk endpoint "/".

    Mengembalikan:
        str: Template HTML yang dirender untuk "index.html".
    """
    return render_template("index.html")


@app.route("/segitiga")
def segitiga():
    """
    Penangan rute untuk endpoint "/segitiga".

    Mengembalikan:
        str: Template HTML yang dirender untuk "segitiga.html".
    """

    return render_template("segitiga.html")


if __name__ == "__main__":
    app.run(use_reloader=True, debug=True)
