var botaoVoltar = document.getElementById("btnVoltar")
var botaoAvancar = document.getElementById("btnAvancar")
var moldura = document.getElementById("moldura")

var path = "imagem/"
var imgs = ['img1.jpg','img2.jpg','img3.jpg','img4.jpg']

var idx = 0
var temporizador = null

window.onload = Inicio

function Inicio()
{
    botaoAvancar.onclick = AvancarImg
    botaoVoltar.onclick  = VoltarImg

    MostrarFoto()
    ResetarTemporizador()
}

function AvancarImg()
{
    if(idx < (imgs.length - 1))
    {
        idx++
    }
    else idx = 0
    
    MostrarFoto()
    ResetarTemporizador()
}

function VoltarImg()
{
    if(idx > 0)
    {
        idx--
    }
    else idx = imgs.length - 1
    
    MostrarFoto()
    ResetarTemporizador() 
}

function MostrarFoto()
{
    moldura.src = path + imgs[idx]
}

function ResetarTemporizador()
{
    clearInterval(temporizador)
    
    temporizador = setInterval(() => {
        if(idx < (imgs.length - 1))
        {
            idx++
        }
        else idx = 0
        
        MostrarFoto()
    }, 2000)
}
