const imageElement = document.getElementById("processedImage") as HTMLImageElement;
const statsElement = document.getElementById("stats") as HTMLDivElement;

// Simulated base64 image (replace with actual output from Android)
const base64Image = "data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAA..."; // truncated

// Simulated stats
const fps = 15;
const resolution = "640x480";

imageElement.src = base64Image;
statsElement.textContent = `FPS: ${fps} | Resolution: ${resolution}`;
