/***********************
  Load Components!

  Express      - A Node.js Framework
  Body-Parser  - A tool to help use parse the data in a post request
  Pg-Promise   - A database tool to help use connect to our PostgreSQL database
***********************/
var express = require('express'); //Ensure our express framework has been added
var app = express();
var bodyParser = require('body-parser'); //Ensure our body-parser tool has been added
app.use(bodyParser.json());              // support json encoded bodies
app.use(bodyParser.urlencoded({ extended: true })); // support encoded bodies

//Create Database Connection
var pgp = require('pg-promise')();

const dbConfig = {
	host: 'ec2-34-197-91-131.compute-1.amazonaws.com',
	port: 5432,
	database: 'd4a5s5mhtltn54',
	user: 'qraoxcgasifrmr',
	password: '1843496aaf165f9ddeef90caa983defb30346e83bb32584efa9734cdb379d6e1'
};

var db = pgp(dbConfig);


// set the view engine to ejs
//app.set('view engine', 'ejs');
app.use(express.static(__dirname + '/'));//This line is necessary for us to use relative paths and access our resources directory

//NO ACCESS
 app.get('/home', function(req, res) {
	res.send('Nothing to see here!')
	});


//Add a gps reading
app.post('/gps', function(req, res, next){
  var latitude = req.query.latitude;
  var longitude = req.query.longitude;
  var speed = req.query.speed;

  console.log(`GPS Reading Insert Attempt with lat:${latitude}, lon: ${longitude}, speed: ${speed}`);

  db.none(`INSERT INTO gps(latitude, longitude, speed)
  VALUES ('${latitude}','${longitude}','${speed}');`)
  .then(function(){
    res.status(200)
    .json({
      status:'success',
      message:'Inserted One GPS Reading'
    });
  })
  .catch(function(err){
    return next(err);
  });
});

//Add an accelerometer reading
app.post('/accel', function(req, res, next){
  var x_accel = req.query.x_accel;
  var y_accel = req.query.y_accel;
  var event_ = req.query.event_

  console.log(`Accel Reading Insert Attempt with x_accel:${x_accel}, y_accel: ${y_accel}, event: ${event_}`);

  db.none(`INSERT INTO accel(x_accel, y_accel, event_)
  VALUES ('${x_accel}','${y_accel}', '${event_}');`)
  .then(function(){
    res.status(200)
    .json({
      status:'success',
      message:'Inserted One Acceleromter Reading'
    });
  })
  .catch(function(err){
    return next(err);
  });
});

//Add an SOS event
app.post('/sos', function(req, res, next){
  var event_ = req.query.event_;

  console.log(`SOS Event Insert Attempt with event: ${event_}`);

  db.none(`INSERT INTO sos(event_)
  VALUES ('${event_}');`)
  .then(function(){
    res.status(200)
    .json({
      status:'success',
      message:'Inserted One SOS event'
    });
  })
  .catch(function(err){
    return next(err);
  });
});

app.listen(process.env.PORT || 5000)
console.log('5000 is the magic port');
