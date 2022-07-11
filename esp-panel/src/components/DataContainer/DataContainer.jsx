import React from "react";
import Wait from "../Messages/Wait";
import EmptyItems from "../Messages/Empty";
import SensorItem from "../Items/SensorItem";
import SliderItem from '../Items/SliderItem';
import SwitchItem from "../Items/SwitchItem";

import "./style.css";

const DataContainer = ({itemsData}) => {
    let Components = Wait();
    if (itemsData.length === 0) {
        Components = EmptyItems()
    } else {
        if(itemsData !== 'wait') {
            Components = itemsData.map((value, index) => {
                let toReturn;
                if(value.type === 'sensor') {
                    toReturn = <SensorItem itemName={value.name} itemVal={value.value} id={value.id} key={index} />;
                }
                if(value.type === 'slider') {
                    toReturn = <SliderItem itemName={value.name} itemVal={value.value} id={value.id} key={index} />;
                }
                if(value.type === 'digital') {
                    toReturn = <SwitchItem itemName={value.name} itemVal={value.value} id={value.id} key={index} />
                }
    
                return(
                    toReturn
                )
            });
        }
    }

    return(
        <div className="dataContainer">
            { Components }
        </div>
    )
}

export default DataContainer;