#!/bin/bash

if [ ! -d ./autoGeneratedJsonClasses ]; then
  mkdir -p ./autoGeneratedJsonClasses;
fi

cp -rf rapidjson autoGeneratedJsonClasses

js2model -l cpp -o autoGeneratedJsonClasses ./js2modelSchemas/sold.schema.json
js2model -l cpp -o autoGeneratedJsonClasses ./js2modelSchemas/result.schema.json
js2model -l cpp -o autoGeneratedJsonClasses ./js2modelSchemas/areas.schema.json
