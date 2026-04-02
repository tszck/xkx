//Edited by fandog, 02/15/2000
inherit ROOM;
void create()
{
    set("short", "古墓");
    set("long",@LONG
這裏陰森森的象是個古代的墓室，一陣陰風吹來，你不由得打了個
寒噤。以前可能有盜墓的人來過，到處是碎瓷片和破紙片，地上有個黑
黝黝的木盒，也不知裏面裝了甚麼古怪東西。
LONG);
	set("exits", ([
		"up" : __DIR__"shangang2",
	]));
	set("objects", ([
		__DIR__"obj/muhe"    : 1,
	]));
	set("coor/x", -1490);
	set("coor/y", -2050);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}