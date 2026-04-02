// Room: /d/5lt/chaguan.c

inherit ROOM;

void create()
{
	set("short", "陶然茶居");
	set("long", @LONG
你一走進來，就聞到一股茶香沁入心脾，精神為之一爽。茶樓東面
擺有數張茶几，上置盆景花木，數名儒生模樣的客人在或高聲談笑，或
交頭接耳，或品茶閒談。你想打聽江湖掌故和謠言，這裏是個好所在。
南牆掛着幾幅字畫，中懸巨幅扇面。中間擺着兩張海梅方桌，各配四張
白瓷凳。此處閒靜淡雅，當是休棲之佳處。
LONG);
	set("resource/water", 1);
	set("exits", ([
		"west"  : __DIR__"sroad1",
	]));
	set("objects", ([
	]));
	set("coor/x", -140);
	set("coor/y", -15);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}