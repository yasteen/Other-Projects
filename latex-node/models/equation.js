const mongoose = require('mongoose');
const createDomPurify = require('dompurify');
const { JSDOM } = require('jsdom');
const dompurify = createDomPurify(new JSDOM().window);

const equationSchema = new mongoose.Schema({
    title: {
        type: String,
        required: true
    },
    latex: {
        type: String,
        required: true
    },
    modifiedAt: {
        type: Date,
        required: true,
        default: Date.now
    }
});

equationSchema.pre('validate', function(next) {
    if (this.latex) {
        this.latex = this.latex.replace(/\$/g, '');
    }
    if (this.latex) {

    }

    next();
});

module.exports = mongoose.model('Equation', equationSchema);