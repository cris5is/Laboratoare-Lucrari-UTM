function setup() {
    createCanvas(400, 400);
}

function draw() {
    background(255);
    fill(255);
    strokeWeight(2);
    ellipse(130, 180, 60, 20);
    ellipse(270, 180, 60, 20);
    fill(255);
    rect(150, 150, 100, 120);
    fill(255, 100, 50);
    triangle(150, 150, 170, 150, 160, 120);
    triangle(230, 150, 250, 150, 240, 120);
    fill(0);
    noStroke();
    ellipse(210, 165, 50, 30);
    ellipse(155, 220, 30, 45);
    ellipse(245, 210, 35, 60);
    fill(255);
    stroke(0);
    strokeWeight(1);
    circle(185, 195, 20);
    circle(215, 195, 20);
    fill(0);
    circle(185, 195, 10); //aici am marit raza la ochiu stang
    circle(215, 195, 10); //aici am marit raza la ochiu drept
    fill(97, 219, 59); //aici am modificat in verde (rbg color picker am folosit)
    stroke(0);
    strokeWeight(2);
    rect(150, 250, 100, 40, 0, 0, 50, 50);
    fill(0);
    circle(185, 275, 8);
    circle(215, 275, 8);
    strokeWeight(0.5);
    text('Cula Cristian,TI-255', 275, 395); //textul
}
