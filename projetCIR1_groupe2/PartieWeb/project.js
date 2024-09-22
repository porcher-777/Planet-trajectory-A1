var planete;
let i = 0;
var OUI;
let x, y, x1, y1, x2, y2, x3, y3, x4, y4 = 0;

function setup() {
  var canvas = createCanvas(1200, 1000);
  canvas.parent('conteneur');
  mL = width/2;
  ml = height/2;
  noLoop();   //Empêcher la fonction draw() de boucler avant de charger le fichier json
  background('rgba(0,0,0,0.7)');
}

function read(input) {
  //Récupérer les éléments du fichier json
  // FileReader pour lire en brut ou JSON.parse() pour lire le JSON
  let fichier = input.files[0];
  let text = new FileReader();
  text.readAsText(fichier);

  text.onload = function() { 
  planete = JSON.parse(text.result); 
    OUI = true;
  };  
  loop(); //la fonction de dessin 
}

function draw() {
  //dessin du Soleil au milieu du canvas
  stroke('yellow');
  strokeWeight('30');
  point(mL, ml);

  //Couleur de la planète
  strokeWeight('0.5');
  fill('purple');

  if(OUI == true){    //Selon la méthode utilisée, la clé du fichier change 
    if (document.getElementById('Euler').checked){
      x = planete['MercureEuler'][i][0][0] * Math.pow(10, -9) + mL;
      y = planete['MercureEuler'][i][0][1] * Math.pow(10, -9) + ml;

      //Couleur de la trajectoire
      stroke('orange');
      ellipse(x, y, 5, 5);
  
      x1 = planete['VenusEuler'][i][0][0] * Math.pow(10, -9) + mL;
      y1 = planete['VenusEuler'][i][0][1] * Math.pow(10, -9) + ml;
      stroke('grey');
      ellipse(x1, y1, 5, 5);

      x2 = planete['HalleyEulerAsymetrique'][i][0][0] * Math.pow(10, -9) + mL;
      y2 = planete['HalleyEulerAsymetrique'][i][0][1] * Math.pow(10, -9) + ml;
      stroke('rgb(169, 169, 169)');
      ellipse(x2, y2, 5, 5);

      x3 = planete['TerreEuler'][i][0][0] * Math.pow(10, -9) + mL;
      y3 = planete['TerreEuler'][i][0][1] * Math.pow(10, -9) + ml;
      stroke('blue');
      ellipse(x3, y3, 5, 5);
  
      x4 = planete['MarsEuler'][i][0][0] * Math.pow(10, -9) + mL;
      y4 = planete['MarsEuler'][i][0][1] * Math.pow(10, -9) + ml;
      stroke('red');
      ellipse(x4, y4, 5, 5);
    }

    else if (document.getElementById('EulerA').checked){
      x = planete['MercureEulerAsymetrique'][i][0][0] * Math.pow(10, -9) + mL;
      y = planete['MercureEulerAsymetrique'][i][0][1] * Math.pow(10, -9) + ml;
      stroke('orange');
      ellipse(x, y, 5, 5);
  
      x1 = planete['VenusEulerAsymetrique'][i][0][0] * Math.pow(10, -9) + mL;
      y1 = planete['VenusEulerAsymetrique'][i][0][1] * Math.pow(10, -9) + ml;
      stroke('grey');
      ellipse(x1, y1, 5, 5);

      x2 = planete['HalleyEulerAsymetrique'][i][0][0] * Math.pow(10, -9) + mL;
      y2 = planete['HalleyEulerAsymetrique'][i][0][1] * Math.pow(10, -9) + ml;
      stroke('rgb(169, 169, 169)');
      ellipse(x2, y2, 5, 5);

      x3 = planete['TerreEulerAsymetrique'][i][0][0] * Math.pow(10, -9) + mL;
      y3 = planete['TerreEulerAsymetrique'][i][0][1] * Math.pow(10, -9) + ml;
      stroke('blue');
      ellipse(x3, y3, 5, 5);
  
      x4 = planete['MarsEulerAsymetrique'][i][0][0] * Math.pow(10, -9) + mL;
      y4 = planete['MarsEulerAsymetrique'][i][0][1] * Math.pow(10, -9) + ml;
      stroke('red');
      ellipse(x4, y4, 5, 5);
    }

    else if (document.getElementById('RK2').checked){
      x = planete['MercureRK2'][i][0][0] * Math.pow(10, -9) + mL;
      y = planete['MercureRK2'][i][0][1] * Math.pow(10, -9) + ml;
      stroke('rgba(255, 127, 0, 0.5)');      
      ellipse(x, y, 5, 5);
  
      x1 = planete['VenusRK2'][i][0][0] * Math.pow(10, -9) + mL;
      y1 = planete['VenusRK2'][i][0][1] * Math.pow(10, -9) + ml;
      stroke('rgb(211, 211, 211)');
      ellipse(x1, y1, 5, 5);

      x2 = planete['HalleyEulerAsymetrique'][i][0][0] * Math.pow(10, -9) + mL;
      y2 = planete['HalleyEulerAsymetrique'][i][0][1] * Math.pow(10, -9) + ml;
      stroke('rgb(169, 169, 169)');
      ellipse(x2, y2, 5, 5);

      x3 = planete['TerreRK2'][i][0][0] * Math.pow(10, -9) + mL;
      y3 = planete['TerreRK2'][i][0][1] * Math.pow(10, -9) + ml;
      stroke('blue');
      ellipse(x3, y3, 5, 5);
  
      x4 = planete['MarsRK2'][i][0][0] * Math.pow(10, -9) + mL;
      y4 = planete['MarsRK2'][i][0][1] * Math.pow(10, -9) + ml;
      stroke('red');
      ellipse(x4, y4, 5, 5);
    }
  }
  i++;
}








