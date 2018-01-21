const socket = io();

const temperatureDisplay = document.getElementById('temperature');

socket.on('temp', function (data) {
  console.log(data);
  temperature.innerHTML = `${data}°C`;
});
