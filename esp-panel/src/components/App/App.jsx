import React, { useState, useEffect } from "react";
import DataContainer from "../DataContainer/DataContainer";
import Title from "../Title";

import './style.css';

// uncomment this and put to dataList for test
// const staticDataList = [
//   {type: 'sensor', name: 'Temperature', value: '20C'},
//   {type: 'digital', name: 'Ventilation', value: "false"},
//   {type: 'slider', name: 'Light', value: "70"},
// ];

function App() {
  const [dataList, setDataList] = useState([]);

  useEffect(() => {
    setDataList('wait');
    fetch('/getAllData')
      .then(resp => resp.json())
      .then(result => {
        setDataList(result);
      })
	  .catch(err => {
		console.log(err);
		setDataList([]);
	  })
  }, []);

  return (
    <div className="mainWindow">
      <Title />
      <DataContainer itemsData={dataList} />
    </div>
  );
}

export default App;
