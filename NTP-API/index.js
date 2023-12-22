const express = require("express");
const bodyParser=require("body-parser");

const {CCRouter} = require('./src/ClientConnector/CC_Routes');
//Initalizing and routing the Client Connector
const ccFunc = express();
ccFunc.use(bodyParser.json());
ccFunc.use(bodyParser.urlencoded({extended:false}));
ccFunc.use(CCRouter);
