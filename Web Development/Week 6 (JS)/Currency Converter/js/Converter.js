function converter(from, to, from_val)
{
    let to_val = 0.0;
    //console.log("inside converter");
    switch(from)
    {
        case "INR": 
            switch(to) 
            {
                case "Pound":
                    to_val = from_val* 0.010;
                    break;

                case "Dollar":
                    to_val = from_val * 0.013;
                    break;

                default:
                    to_val = from_val;
                    break;
            }
            break;
                    
        case "Pound": 
            switch(to) 
            {
                case "INR":
                    to_val = from_val * 98.53;
                    break;

                case "Dollar":
                    to_val = from_val * 1.33;
                    break;

                default:
                    to_val = from_val;
                    break;
            }
            break;
        
        case "Dollar": 
            switch(to) 
            {
                case "Pound":
                    to_val = from_val * .75;
                    break;

                case "INR":
                    to_val = from_val * 74.16;
                    break;

                default:
                    to_val = from_val;
                    break;
            }
            break;

        default:
            alert("OOPS! Something went Wrong");
    }
    return to_val.toFixed(2);
}