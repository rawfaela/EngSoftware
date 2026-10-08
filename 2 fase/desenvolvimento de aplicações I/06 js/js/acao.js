// JavaScript Document

//Manipulando o DOM
//* ";" é opicional


var nome = "Rafa"
var idade = 19
//console.log("Meu nome é: " + nome)
//console.log("Minha idade é: " + idade)
//console.log(VerificaIdade(idade))

function VerificaIdade(valor) {
    console.log(VerificaSePos(valor))
    if (valor >= 18)
    {
        return true
    }
    else
    {
        return false
    }
}

function VerificaSePos(valor)
{
    if (valor < 0)
    {
        return false
    }
    else
    {
        return true
    }
}


const h3 = document.querySelector("h3")
//console.log(h3.innerText)
h3.innerText = "Aula de Web"

var h5 = document.querySelector("h5")
//console.log(h5.innerText)
h5.innerText = "Introdução a JavaScript"

var pTexto = document.querySelector("p")
//console.log(pTexto.innerText)

var pTextoComId = document.getElementById("textoB")
//console.log(pTextoComId.innerText)
pTextoComId.innerText = "Lista de Compras"

var li = document.querySelector("li")
//console.log(li.innerText)

var liLista = document.querySelectorAll("li")
console.log(liLista) //* vem 3 OBJETOS (uma lista)
//console.log(liLista[2].innerText) 
liLista[1].innerText = "Chocolate"

function ListarElementos()
{
    if (liLista.length < 1)
    {
        console.log("Nenhum elemento encontrado")
    }
    else
    {
        for (i = 0; i < liLista.length; i++ )
        {
            console.log(liLista[i].innerText)
        }
    }
}

var AddBtn = document.getElementById("addBtn")
AddBtn.onclick = AddNegrito //* associação da função com o evento

function AddNegrito()
{
    if (h3.className != "negrito")
    {
        h3.className = "negrito"
        AddBtn.innerText = "Remover Negrito"
    }
    else
    {
        h3.classList.remove("negrito")
        AddBtn.innerText = "Adicionar Negrito"
    }
}

//Adicionando Texto no corpo
// const body = document.body
// body.append("teste")


// //Criando um Elemento
// const article = document.createElement("article")

// //Criando um Elemento
// const p = document.createElement("p")


// // Adicionado o texto ao Elemento Article
// article.innerText = "Artigo"


// //Adicionando HTML dentro do H2
// p.innerHTML = "<strong> TEXTO STRONG </strong>"
// //p.innerHTML = "TEXTO STRONG"

// //Adicionado o tag Article no Body
// body.append(article)

// //Adicionando a tag p no Article

// article.append(p);


