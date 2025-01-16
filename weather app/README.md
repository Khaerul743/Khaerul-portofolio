# Weather App

A responsive weather application that provides real-time weather updates for any city. This app also includes automatic location detection and error handling for invalid inputs.

## Features
- Search weather by city name.
- Automatically detect the user's location.
- Display temperature, humidity, wind speed, and weather description.
- Responsive design for various screen sizes.
- Error alerts for invalid inputs or failed location detection.

## Folder Structure
```
Weather-App/
├── assets/
│   ├── style/
│   │   └── style.css
│   ├── script/
│   │   └── main.js
├── index.html
└── README.md
```

## How to Run the Application

1. Clone this repository or download it as a ZIP file and extract it.
2. Open the project folder and ensure the file structure matches the layout above.
3. Open `index.html` in any modern browser to run the application.

## Usage Instructions

1. **Search for Weather by City:**
   - Enter the name of a city in the search box.
   - Click the "Search" button.
   - The weather information will display if the city is found.

2. **Use Automatic Location Detection:**
   - Click the "Find yout location" button.
   - Location is taken using ip API.
   - The weather information for your location will display.

3. **Error Handling:**
   - If the city is not found, an error message will appear.
   - If location detection fails, an error message will notify you.

## Technologies Used
- HTML
- CSS (stored in `assets/style/style.css`)
- JavaScript (stored in `assets/script/main.js`)

## Future Improvements
- Add a weekly weather forecast feature.
- Integrate multiple language support.
- Enhance UI/UX with animations.

## License
This project is open-source and available under the MIT License.