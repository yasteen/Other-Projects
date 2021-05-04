const express = require('express');
const Equation = require('../models/equation');
const router = express.Router();

// Get all

router.post('/', async (req, res, next) => {
    req.equation = new Equation();
    next();
}, saveEquationAndReload('new'));

router.put('/:id', async(req, res, next) => {
    req.equation = await Equation.findById(req.params.id);
    next();
}, saveEquationAndReload('edit'));

router.delete('/:id', async(req, res) => {
    await Equation.findByIdAndDelete(req.params.id);
    reload(res);
});

function saveEquationAndReload(path) {
    return async (req, res) => {
        let equation = req.equation;
        equation.title = req.body.title;
        equation.latex = req.body.latex;
        try {
            equation = await equation.save();
            reload(res);
        } catch (err) {
            console.error(err);
        }
    }
}

function reload(res) {
    res.redirect('/');
}

module.exports = router;