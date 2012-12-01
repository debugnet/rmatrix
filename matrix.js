function matrix(){
var canvas = document.getElementById("matrix");
var ctx = canvas.getContext("2d");
//Make the canvas occupy the full page
var maxx = window.innerWidth, maxy = window.innerHeight;
canvas.width = maxx;
canvas.height = maxy;
var x;

ctx.setLineWidth(1);
var lines=Math.round(Math.random()*2*(maxx+maxy))+1;
var matrix=new Array(lines);
for(x=0;x<matrix.length;x++){matrix[x]=new Array(4);}

function reinit(){
matrix[x][1]=-Math.round(Math.random()*maxy);//*2);
matrix[x][2]=-Math.round(Math.random()*maxy);//*2);
if(matrix[x][2]>=matrix[x][1]){matrix[x][2]-=Math.round(Math.random()*maxy);}
matrix[x][3]=Math.round(Math.random()*maxx);
matrix[x][4]=Math.random();
}

for(x=0;x<lines;x++){reinit();}

function drawmatrix(){
for(x=0;x<lines;x++){
//green
if(0.75>Math.random()){ctx.fillStyle = "rgba(16,64,16,1)";}else{ctx.fillStyle = "rgba(0,32,0,1)";}
if(matrix[x][1]>=0){ctx.fillRect(matrix[x][3],matrix[x][1],1,1);}
if(matrix[x][4]>Math.random()){matrix[x][1]++;}
//white
ctx.fillStyle = "rgba(96,128,96,1)";
if(matrix[x][1]>=0){ctx.fillRect(matrix[x][3],matrix[x][1],1,1);}
if(matrix[x][4]>=Math.random()){
matrix[x][2]++;
if(matrix[x][2]>=matrix[x][1]){matrix[x][2]=matrix[x][1]-1;}
if(matrix[x][2]>maxy){reinit();}
}
if(matrix[x][2]>=0){
ctx.fillStyle = "black";
ctx.fillRect(matrix[x][3],matrix[x][2],1,1);
//ctx.fillStyle = "rgba(0,64,0,1)";
}
}
}
setInterval(drawmatrix,Math.round(Math.random()*20));
}

