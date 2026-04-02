//Room: /d/dali/jingzhuang1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","第一層");
	set("long",@LONG
雕四大天王像，高約四尺，披甲戴胄，手持斧鉞，威嚴莊重。三
人足踏鬼奴。一鬼奴肌肉暴起，右手挽蛇，蛇嘴正觸鬼奴下齶；另倆
鬼奴戴鐐。一天神足下三人，中間一人正以雙手各託天王一足。天王
之間遍刻梵文佛經。
LONG);
	set("exits",([ /* sizeof() == 1 */
	    "up"    : __DIR__"jingzhuang2",
	    "out"   : __DIR__"jinzhihe",
	]));
	set("no_clean_up", 0);
	set("coor/x", -36000);
	set("coor/y", -70400);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}