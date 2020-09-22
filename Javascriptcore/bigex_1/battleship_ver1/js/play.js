//playgame

function gun(){
	count++;
	
	if(this.childElementCount != 1){
		document.getElementById("notice").innerHTML = ""
		+ "Thong bao tu trung tam : Ban ban MIss CMNR >.< | <br/> Luot :" + count +" | enemy : "+ enemy;
		this.style.backgroundColor = "gray";
	}
	else{
		var x = this.firstElementChild;
		x.removeAttribute("class");
		
		enemy--;
		document.getElementById("notice").innerHTML = ""
		+ "Thong bao tu trung tam : Ban ban trung 1 tau dich <br/>Luot = "+ count +" | enemy : "+ enemy;
		
		var context = this.innerHTML;
		context += "<i></i>"
		this.innerHTML = context;
	}
	if(!enemy) alert("YOU WIN whit" + count + "luot HIHI! ");
}
// check map

// AI action
 