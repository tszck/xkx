// jiashan.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;
void create()
{
	set("short","假山小池");
	set("long",@LONG
這是另一個小園子，裏頭有個小池塘。四周布有假山，增添林園美
景。下雨時雨水落入溪塘中，清脆的水珠聲有如玉珠落盤般悅耳。水氣
朦朧中抬頭西望，只見遠處蒼山如黛，若隱若現，雨景妙趣無窮。
LONG);
	set("exits",([
		"east" : __DIR__"houyuan",
	]));
	set("objects", ([
		"/clone/medicine/vegetable/shengdi" : random(2),
	]));
	set("outdoors", "huashan");
	set("coor/x", -890);
	set("coor/y", 210);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
 
