// 1. Importar Express usando la sintaxis de ES Modules
import express from 'express';

// 2. Crear la instancia de la aplicación
const app = express();
const PORT = 3000;

app.use(express.json());

// 3. Configurar la ruta básica
app.get('/', (req, res) => {
    res.send('¡Hola, mundo desde Express con ES Modules!');
});

app.post('/send', (req, res) => {
    let { number } = req.body;
    console.log(number);
    res.send("gracias por el dato")
});

// 4. Iniciar el servidor
app.listen(PORT, () => {
    console.log(`Servidor corriendo en http://localhost:${PORT}`);
});
