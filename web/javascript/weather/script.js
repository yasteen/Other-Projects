const apikey = '3533a307d1773db35974c5d86c764015';

const main = document.getElementById("main");
const form = document.getElementById("form");
const search = document.getElementById("search");
const url = (city) => `https://api.openweathermap.org/data/2.5/weather?q=${city}&units=metric&appid=${apikey}`

async function getWeatherByLocation(city) {
    const resp = await fetch(url(city), { origin: "cors" });
    const respData = await resp.json();

    console.log(respData);

    addWeatherToPage(respData);
}

function addWeatherToPage(data) {
    const weather = document.createElement('div');
    m = data.main;
    if (typeof m === "undefined") {
        weather.className = '';
        weather.classList.add("error");
        weather.innerHTML = `<small>${search.value} is not a valid location.</small>`
    } else {
    const temp = Math.floor(data.main.temp);
    weather.className = '';
    weather.classList.add("weather");

    weather.innerHTML = `
        <h2><img src="http://openweathermap.org/img/wn/${data.weather[0].icon}@2x.png" />
        ${temp} &#176C
        <img src="http://openweathermap.org/img/wn/${data.weather[0].icon}@2x.png" /></h2>
        <small>${data.weather[0].main}</small>
    `;

    }

    //clean up
    main.innerHTML = '';

    main.appendChild(weather);
}

form.addEventListener("submit", (e) => {
    e.preventDefault();
    const city = search.value;

    if(city) {
        getWeatherByLocation(city);
    }
});