
//This was written inline for the HTML form (which I have also supplied as scoretest.html
//for your viewing/testing)
function scoretest(form) {
    let answer_1
    let answer_2
    let answer_3
    console.log(form);
    console.log(exampleFormControlSelect1[3].selected);
    console.log(form.Q2[3].checked); //radio buttons test
    console.log(form.Q3.value);
    if(exampleFormControlSelect1[3].selected === true){
        answer_1 = "Right";
    }else{answer_1 = "Wrong"}
    console.log(answer_1)
    if(form.Q2[3].checked === true){
        answer_2 = "Right";
    }else{answer_2 = "Wrong"}
    console.log(answer_2)
    if(form.Q3.value === 'fruit' || form.Q3.value === 'Fruit'){
        answer_3 = "Right";
    }else{answer_3 = "Wrong"}
    console.log(answer_3)
    window.alert("Q1: " + answer_1 + "\n" + "Q2: " + answer_2 + "\n" + "Q3: " + answer_3);
}