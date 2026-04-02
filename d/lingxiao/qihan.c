// Room: /d/lingxiao/qihan.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","氣寒軒");
	set("long",@LONG
這裏是凌霄城大弟子白萬劍及其家人的住所。牆上掛着一副中堂，
上書“氣寒西北”，筆法粗獷，顯是名家手跡。桌上放着一壺參陽玉酒，
酒香四溢，一位面貌英俊的男子坐在桌旁，正悠閒自得地修剪桌上的一
盆梅花。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"east" : __DIR__"houyuan2", 
	]));
	set("objects", ([
		CLASS_D("lingxiao")+"/bai1" : 1,
	]));
	set("coor/x", -31010);
	set("coor/y", -8850);
	set("coor/z", 140);
	setup();
}
