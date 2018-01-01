#!/bin/bash

if [ ! -d ./autoGeneratedJsonClasses ]; then
  mkdir -p ./autoGeneratedJsonClasses;
fi

cp -rf rapidjson autoGeneratedJsonClasses

js2model -l cpp -o autoGeneratedJsonClasses sold.schema.json
js2model -l cpp -o autoGeneratedJsonClasses result.schema.json
js2model -l cpp -o autoGeneratedJsonClasses areas.schema.json
