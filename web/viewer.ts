window.onload = () => {
  const imageElement = document.getElementById("processedImage") as HTMLImageElement;
  const statsElement = document.getElementById("stats") as HTMLDivElement;

  const images: string[] = ["nika.png", "nika2.png"];
  let index: number = 0;

  setInterval(() => {
    const currentImage = images[index % images.length];
    const fps: number = 15 + index;
    const resolution: string = "1920x1080";

    imageElement.src = currentImage;
    statsElement.textContent = `FPS: ${fps} | Resolution: ${resolution}`;

    index++;
  }, 1000);
};
