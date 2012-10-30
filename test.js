var csegment = require("./build/Release/csegment");

var content = "";
process.argv.forEach(function (val, index, array) {
	if(index == 2)
		content = val;
});

csegment.doWork(content, function(result) {console.log(result);});
csegment.doWork('结婚的和尚未结婚的', function(result) {console.log(result);});
csegment.doWork('中外科学名著', function(result) {console.log(result);});
csegment.doWork('鞭炮声响彻夜空', function(result) {console.log(result);});
csegment.doWork('努力学习语法规则', function(result) {console.log(result);});
csegment.doWork('提高产品质量', function(result) {console.log(result);});
csegment.doWork('北京大学生前来应聘', function(result) {console.log(result);});
csegment.doWork('独立自主和平等互利的原则', function(result) {console.log(result);});
csegment.doWork('为人民办公益', function(result) {console.log(result);});
csegment.doWork('他说的确实在理', function(result) {console.log(result);});
csegment.doWork('这事的确定不下来', function(result) {console.log(result);});
csegment.doWork('把手抬起来', function(result) {console.log(result);});
csegment.doWork('这扇门的把手', function(result) {console.log(result);});
csegment.doWork('学生会宣传部', function(result) {console.log(result);});
csegment.doWork('邓颖超生前使用过的物品', function(result) {console.log(result);});
csegment.doWork('费孝通向人大常委会提交书面报告', function(result) {console.log(result);});
