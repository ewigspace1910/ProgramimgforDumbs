/*
	load game
		- making map
		- generate ship
		- addEventListener to cell
		-reset configure pregame
*/
window.onload = function(){
	mapgame.createGame();
}

var mapgame ={
	createGame : function(){
		
		this.resetgame();
		this.generateMap();
		this.generateShip();
	},
	generateMap : function(){
		var board = document.getElementById("board");
		var tble = "\n <table> \n";
	
		for (var i=0;i<=10;i++){
			tble +="<tr> \n" ;
			for (var j=0; j<=10;j++){
				if(i===0 && j!=0) tble += '<td>' + j + ' </td> ';
				else if(j===0 && i!=0) tble += '<td>' + i + ' </td> ';
				else tble += '<td id="' + i + j + '"></td> ';
			}
			tble += "</tr>\n";
		}
		tble += "</table> \n";
		board.innerHTML = tble;
	},
	
	generateShip : function(){
		
	},
	
	resetgame : function(){
		ControlerObj.resetObj();
		ModelObj.resetObj();
	}
}