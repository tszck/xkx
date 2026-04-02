// Room: /city/huapeng.c

inherit ROOM;

void create()
{
	set("short", "芍藥圃");
	set("long", @LONG
揚州芍藥，擅名天下，禪寺前的這塊芍藥圃尤其宏偉，只見花圃中
名種千百，花大如碗，煞是瑰麗。當日影漸漸西斜。日光照在花棚外數
千株芍藥之上，璀燦華美，真如織錦一般。其中一株芍藥開了四朵大花，
花瓣深紅，腰有金線，便是著名的金帶圍了。
LONG );
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"chanzhimenqian",
		"west"  : __DIR__"huadian",
	]));
	set("coor/x", -30);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}