let pesoTxt = document.getElementById("pesoTxt") //peso
let alturaTxt = document.getElementById("alturaTxt") // altura

function carregar(){
    let IMC = (Number(pesoTxt.value) / (Number(alturaTxt.value) ** 2)).toFixed(2)

    document.getElementById("res").textContent = "Seu IMC é " + IMC
    
    if(IMC < 18.49){ //ira identificar o tipo do IMC
        document.getElementById("tipo").textContent = "Tipo: Abaixo do peso ideal."
    } else if(IMC >= 18.5 && IMC <= 24.99){
        document.getElementById("tipo").textContent = "Tipo: Esta no peso ideal."
    } else if(IMC >= 25 && IMC <= 29.99){
        document.getElementById("tipo").textContent = "Tipo: Pré-Obeso."
    } else if(IMC >= 30 && IMC <= 34.99){
        document.getElementById("tipo").textContent = "Tipo: Obesidade Grau I."
    
    } else if(IMC >= 35 && IMC <= 39.99){
        document.getElementById("tipo").textContent = "Tipo: Obesidade Grau II."
    
    } else if(IMC >= 40){
        document.getElementById("tipo").textContent = "Tipo: Obesidade Grau III."
    
    }
}