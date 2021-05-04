# Latex Equations

A small program for saving, loading, and editing LaTeX equations to/from a database.

![](https://raw.githubusercontent.com/yasteen/Random-Projects/main/latex-node/screenshots/screenshot.png)

This project uses Node, Express, ejs, MongoDB, and MathJax.

## To use

Run the following commands:
```bash
$ git clone https://github.com/yasteen/Random-Projects.git
$ cd Random-Projects/latex-node
$ npm install
```
Create a `.env` file referencing to MongoDB, then run
```bash
$ echo "DATABASE_URL=mongodb://localhost/latex_equations" > .env
$ npm start
```
