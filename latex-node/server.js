// Dependencies
if (process.env.NODE_ENV !== 'production') {
    require('dotenv').config();
}
require('mathjax-full').init({
    startup: {
        typeset: false
    },
    loader: {
        load: ['input/tex', 'output/svg']
    }
});

const express = require('express');
const mongoose = require('mongoose');
const Equation = require('./models/equation');
const equationRouter = require('./routes/equations');
const methodOverride = require('method-override');
const app = express();



// Mongoose set-up
mongoose.connect(process.env.DATABASE_URL, {
    useNewUrlParser: true, useUnifiedTopology: true
});

// App
app.set('view engine', 'ejs');
app.use(express.urlencoded({extended: false}));
app.use(methodOverride('_method'));


app.get('/', async (req, res) => {
    const equations = await Equation.find().sort({ modifiedAt: 'desc'});
    equations.forEach(equation => {
        equation.svg = MathJax.tex2svg(equation.latex, {display: true});
        equation.svg = MathJax.startup.adaptor.outerHTML(equation.svg);
    });
    // const equations = [{
    //     title: 'Titre',
    //     latex: '$hi$'
    // }]
    res.render('equations/index', { equations: equations });
});

app.use(express.static(__dirname + '/public'))

app.use('/equations', equationRouter);

app.listen(3000);