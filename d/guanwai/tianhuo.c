// /guanwai/tianhuo.c

inherit ROOM;

void create()
{
	set("short", "天豁峯");
	set("long", @LONG
乘槎河東岸，與龍門峯對峙。峯頂如鷹嘴般的峻峭山峯破石而出，
伸向天池，故又名鷹嘴峯。古書載：“峯起雙尖，中闢一線，有豁然開
朗、令人不可思議之趣”，相傳爲大禹治水所劈，石多赤色，猶如二龍
蟠踞，妙趣橫生。
LONG );
	set("exits", ([
		"south" : __DIR__"huagai",
		"west"  : __DIR__"longmen",
	]));
	set("no_clean_up", 0);
	set("outdoors", "changbai");
	set("coor/x", 6200);
	set("coor/y", 5180);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}