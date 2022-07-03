'use strict';

const HELPER_BASE = process.env.HELPER_BASE || "/opt/";

const config = {
  channelAccessToken: '[LINEのチャネルアクセストークン]',
  channelSecret: '[LINEのチャネルシークレット]',
};

const LineUtils = require(HELPER_BASE + 'line-utils');
const line = require('@line/bot-sdk');
const app = new LineUtils(line, config);

app.beacon( async (event, client) =>{
	console.log(event);

	var message = app.createSimpleResponse("ビーコン(" + event.beacon.dm + ")の受信圏内に入りました");
	return client.replyMessage(event.replyToken, message);
});

exports.fulfillment = app.lambda();
