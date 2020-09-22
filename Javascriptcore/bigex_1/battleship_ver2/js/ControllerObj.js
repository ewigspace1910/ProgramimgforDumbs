//here is ControlerObject
var ControlerObj = {
	numguess 	: 0,
	iswin 		: 0,
	
	checkguess :function(){
		if(!this.iswin){
			var input = document.getElementById("txtInput");
			var guess = input.value;
			if (guess.length !== 2 || isNaN(guess)) return null;
			
			if (guess > ModelObj.boardsize ** 2 || guess < 0) return null;
			if( ModelObj.fire(guess)) this.numguess++; ;
			
			input.value ="";
			
			if(ModelObj.shipsuck  === ModelObj.numship){
				this.iswin = 1;
				alert("Congratulation!!! You Win affer " + this.numguess + "step" );
				alert("There are " + ModelObj.numship +" enemyship been sunk");
				
			}
			
		}
	},
	
	resetObj :function(){
		this.numguess = 0;
		this.iswin 	= 0;
	}
}