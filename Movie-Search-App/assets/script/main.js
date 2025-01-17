const searchBtn = document.querySelector("#search-btn");
const inputUser = searchBtn.previousElementSibling;
const loading = document.querySelector("#modal-loading");

searchBtn.addEventListener("click", async function(){  
    const movies = await getMovies(inputUser.value);
    const filmContainer = document.querySelector("#film-container");
    let cards = cardsFilm(movies);
    loading.classList.remove("active");
    filmContainer.innerHTML = cards;
})

function getMovies(keyword){
    loading.classList.add("active");
    return fetch("http://www.omdbapi.com/?apikey=8df92dc6&s="+keyword)
                .then(response => response.json())
                .then(json => json.Search)
}

function cardsFilm(data){
    let buffer = '';
    data.forEach((el) => {
        buffer += `
            <div class="film-card">
                <div class="film-image">
                    <img src="${el.Poster}" alt="Film Poster">
                </div>
                <div class="card-content">
                    <h3>${el.Title}</h3>
                    <p>${el.Year}</p>
                    <button class="details-btn">Show Details</button>
                    <data value = "${el.imdbID}"></data>
                </div>
            </div>
        `
    })
    return buffer;
}

document.addEventListener("click",async function(e){
    if(e.target.classList.contains("details-btn")){
        let movieId = getIDMovie(e);
        let movieDescription = await getDescriptionMovie(movieId);
        showDescription(movieDescription);
    }else if(e.target.classList.contains('close-btn')){
        e.target.parentElement.parentElement.classList.add("hidden")
    }
})

function getIDMovie(e){
    const id = e.target.nextElementSibling.value;
    return id
}

function getDescriptionMovie(idMovie){
    loading.classList.add("active");
    return fetch("http://www.omdbapi.com/?apikey=8df92dc6&i="+idMovie)
    .then(response => response.json())
    .then(json => json)
}

function showDescription(movieDescription){
    const filmModal = document.querySelector('#film-modal');
    loading.classList.remove("active");
    filmModal.classList.remove("hidden");
    filmModal.innerHTML = `
            <div class="modal-content">
                <span class="close-btn" id="close-btn">&times;</span>
                <h2 id="film-title">${movieDescription.Title}</h2>
                <p><strong>Genre:</strong> <span id="film-genre">${movieDescription.Genre}</span></p>
                <p><strong>Director:</strong> <span id="film-director">${movieDescription.Director}</span></p>
                <p><strong>Country:</strong> <span id="film-country">${movieDescription.Country}</span></p>
                <p><strong>Rating:</strong> <span id="film-rating">${movieDescription.imdbRating}</span></p>
                <p><strong>Synopsis:</strong></p>
                <p id="film-synopsis">${movieDescription.Plot}</p>
            </div>
    `
}

