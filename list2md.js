const number;

let lines = "";

$("#question-app tbody tr").each((index, tr) => {
    if (index < number) {
        let line = ""; //|  | []() | Medium |  |
        line += "| ";
        line += $(tr).find("td:eq(1)").text();
        line += " | [";
        line += $(tr).find("td:eq(2) a").text();
        line += "](";
        line += ($(tr).find("td:eq(2) a").prop("href") + ") | ");
        line += $(tr).find("td:eq(5) span").text() + " |  |\n";
        lines += line;
    }
});

console.log(lines);