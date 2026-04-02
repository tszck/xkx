// Room: /d/taohua/jicui.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "積翠亭");
	set("long", @LONG
竹林內有座竹枝搭成的涼亭，亭上橫額在月光下看得分明，是“積
翠亭”三字，兩旁懸着副對聯(duilian) 。亭中放着竹臺竹椅，全是多
年之物，用得潤了，月光下現出淡淡黃光。竹亭之側並肩生着兩棵大松
樹，枝幹虯盤，只怕已是數百年的古樹。蒼松翠竹，清幽無比。
LONG
	);
	set("exits",([
		"north" : __DIR__"hetang",
		"east"  : __DIR__"kefang",
		"south" : __DIR__"caodi",
	]) );
	set("no_clean_up",0);
	set("outdoors","taohua");
	set("item_desc",([
		"duilian" : "
桃                   碧
花                   海
影                   潮
裏                   生
飛                   按
神                   玉
劍                   簫\n
"
	]) );
	set("objects",([
		CLASS_D("taohua")+"/huang" : 1,
	]) ); 

	set("coor/x", 9010);
	set("coor/y", -3030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}