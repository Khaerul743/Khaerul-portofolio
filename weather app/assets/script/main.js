const container = document.querySelector(".container");
const searchInput = document.querySelector("#city-input");
const loading = document.querySelector(".loader");

container.addEventListener("click",async function(e){
    if(e.target.classList.contains("search-btn")){
        const weatherInfoDisplay = document.querySelector(".weather-info");
        weatherInfoDisplay.classList.remove('show');
        const weather = await getWeather(searchInput.value);
        const current = weather.current;
        const location = weather.location;
        loading.style.display = 'none';
        showInfo(current,location)
    }else if(e.target.classList.contains("auto-location-btn")){
        const weatherInfoDisplay = document.querySelector(".weather-info");
        weatherInfoDisplay.classList.remove('show');
        const yourLocation = await getLocation();
        const weather = await getWeather(yourLocation);
        const current = weather.current;
        const location = weather.location;
        loading.style.display = 'none';
        showInfo(current,location)
    }
})

async function getWeather(inputUser){
    const loading = document.querySelector(".loader");
    const errorDisplay = document.querySelector('#error-message');
    const weatherInfoDisplay = document.querySelector(".weather-info");
    loading.style.display = 'block';
    try{
        let url = "http://api.weatherapi.com/v1/current.json?key=568ae9c9563b488299c141148251001&q="+inputUser;
        const response = await fetch(url);
        if(!response.ok){
            throw new Error("Location not found");
        }else{
            errorDisplay.classList.remove("show")
            errorDisplay.children[0].innerText = '';
            weatherInfoDisplay.style.display = 'block';
            return fetch(url)   
                    .then(response => response.json())
                    .then(json => json)
        }
    }catch(err){
        weatherInfoDisplay.style.display = 'none';
        errorDisplay.classList.add("show");
        errorDisplay.children[0].innerText = err;
    }
}

async function showInfo(current,location){
    const weatherInfoDisplay = document.querySelector(".weather-info");
    weatherInfoDisplay.classList.add("show");
    weatherInfoDisplay.innerHTML = `
    <h2 id="city-name">${location.name}</h2>
    <p class = "country">${location.country}</p>
    <p id="date">${location.localtime}</p>

    <div class="weather-details">
        <img id="weather-icon" src="${current.condition.icon}" alt="Weather Icon">
        <div>
            <h3 id="temperature">${current.temp_c}°C</h3>
            <p id="description">${current.condition.text}</p>
        </div>
    </div>

    <div class="additional-info">
        <p>Humidity: <span id="humidity">${current.humidity}%</span></p>
        <p>Wind Speed: <span id="wind-speed">${current.wind_kph} km/h</span></p>
    </div>   
    `
}

//get your location
function getLocation(){
    return fetch("https://ipapi.co/json")
                .then(response => response.json())
                .then(json => json.city)
}