//here is ViewObject
var ViewObj ={
	/*mission :
		-method to nofice mesage
		-method to display ship hit by id "00"
		-method display miss 
	*/
	sentMessage : function(msg){
		var mess = document.getElementById("messageBox");
		mess.innerText = "Thong bao : " + msg;
	},
	displayHit : function(loca){
		var cell = document.getElementById(loca);
		cell.setAttribute("class","hit");
		
	},
	displayMiss : function(loca){
		var cell = document.getElementById(loca);
		cell.setAttribute("class","miss");
	}
}