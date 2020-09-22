//here is ModelObj
var ModelObj ={
	boardsize 	: 10,
	numship 	: 2,
	shipsuck 	: 0,
	shiplenght 	: 2,
	ships : [
		{locations : ["22","23"], ishits : ["",""] },
		{locations : ["32","42"], ishits : ["",""]}
	],
	steplogs : [],
	
	fire : function(guess){
		if(this.steplogs.indexOf(guess) >= 0){
			ViewObj.sentMessage("ban lap lai luot cu");
			return 0;
		} 
		//push method to save prestep
		this.steplogs.push(guess);
		for(var i=0;i< this.numship ;i++){
			var ship = this.ships[i];
			var index = ship.locations.indexOf(guess);
			if (index >= 0){
				ship.ishits[index] = "hit";
				ViewObj.displayHit(guess);
				if(this.isshunk(ship)){
					this.shipsuck++;
					ViewObj.sentMessage("ban danh sap 1 chien ham!");
				}else{
					ViewObj.sentMessage("ban ban trung 1 chien ham!");
				}
				return 1;
			}
		}
		ViewObj.displayMiss(guess);
		ViewObj.sentMessage("ban da phan doan sai!");
		return 1;
	},
	
	isshunk :function(ship){
		for(var i = 0; i<ship.ishits.length; i++){
			if (ship.ishits[i]==="") return 0;
		}
		return 1;
	},
	
	resetObj :function(){
		this.boardsize = 0;
		this.numship = 0;
		this.shipsuck = 0;
		this.shiplenght = 0;
		this.ships = [];
		this.steplogs = [];
	}
}