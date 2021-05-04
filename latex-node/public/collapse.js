
var edit = document.getElementsByClassName('edit');

for (var i = 0; i < edit.length; i++) {
    edit[i].addEventListener('click', function() {
        setActive(this);
    })
}

function setActive(editButton) {
    editButton.classList.toggle('active');
    var content = editButton.nextElementSibling;
    if (content.style.height) {
        content.style.height = null;
    } else {
        content.style.height = content.scrollHeight + 'px';
    }
    for (var i = 0; i < edit.length; i++) {
        if (edit[i] !== editButton && edit[i].classList.contains('active')) {
            edit[i].classList.remove('active');
            edit[i].nextElementSibling.style.height = null;
        }
    }
}