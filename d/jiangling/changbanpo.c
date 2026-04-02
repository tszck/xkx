//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{

	set ("short", "長坂坡");
	set ("long", @LONG
三國時這裏是著名的戰場。史載，東漢建安十三年（公元 208年）
劉備被曹操追擊至此，與張飛等數十人騎馬脫逃，隨軍眷屬被曹軍圍困
於此，部將趙雲單槍匹馬，身抱劉備之子阿斗，浴血奮戰，力保劉妻甘
夫人突圍。北面遙對錦屏山，傳爲當時曹操登高觀陣之處，景色秀麗，
風光宜人。 
LONG);
	set("exits", ([  
		"east" : __DIR__"dangyangqiao",
	]));
	set("outdoors", "jiangling");
	set("no_clean_up", 0);
	set("coor/x", -1510);
	set("coor/y", -2070);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
