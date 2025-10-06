window.onload = function () {
    var imageElement = document.getElementById("processedImage");
    var statsElement = document.getElementById("stats");
    var images = ["nika.png", "nika2.png"];
    var index = 0;
    setInterval(function () {
        var currentImage = images[index % images.length];
        var fps = 15 + index;
        var resolution = "1920x1080";
        imageElement.src = currentImage;
        statsElement.textContent = "FPS: ".concat(fps, " | Resolution: ").concat(resolution);
        index++;
    }, 1000);
};
