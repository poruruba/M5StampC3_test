'use strict';

const HELPER_BASE = process.env.HELPER_BASE || "/opt/";

exports.handler = async (event, context) => {
  console.log(event);

  context.send(JSON.stringify({ message: "Hello" } ));
};
