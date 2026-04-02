// Room: /d/lingxiao/feihua.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","飛花閣");
	set("long",@LONG 
這是凌霄城長門第六代弟子，「寒梅女俠」花萬紫的居所，樓名飛
花閣。花萬紫是凌霄城六代弟子中唯一的女性，一來為避嫌，二來花萬
紫本就性喜清淨，故一人獨居於此。此處是花園小樓之上，憑窗而望，
千萬朵梅花迎雪飛舞，萬梅飄零，紛紛而下。桌上放着一束五顏六色的
梅花。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"down"  : __DIR__"huajing",  
	]));
	set("objects", ([
		CLASS_D("lingxiao")+"/hua" : 1,
	]));
	set("coor/x", -31010);
	set("coor/y", -8880);
	set("coor/z", 150);
	setup();
	replace_program(ROOM);
}

