//Edited by fandog, 01/31/2000

inherit ROOM;
void create ()
{
	set ("short", "花圃");
	set ("long", @LONG
這是知府衙門裏的花圃。花圃中有幾盆顏色特別嬌豔的黃花。這些
花的花瓣黃得象金子一樣，閃閃發亮，花朵的樣子很象荷花，只是沒荷
花那麼大。北邊是知府大人的書房，南邊是客廳。東邊是知府大人和家
眷的住處。
LONG);
	set("outdoors", "jiangling");
	set("exits", ([ 
		"north" : __DIR__"shufang",
		"south" : __DIR__"keting",
		"east"  : __DIR__"dongxiang",
		"west"  : __DIR__"datang",
	]));
	set("objects", ([
		__DIR__"obj/jinboxunhua" : 2,
	]));

	set("coor/x", -1488);
	set("coor/y", -2030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
