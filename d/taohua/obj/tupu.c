// tupu.c

inherit ITEM;

void create()
{
        set_name("九宮八卦圖譜", ({ "tupu", "book", "shu" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
		set("long", "
九宮歌訣：九宮之義，法以靈龜。二四爲肩，六八爲足；左三右七，戴九履一；五居中間。
八卦圖解：乾三連，坤六段；離中虛，坎中滿；震仰盂，艮覆碗；兌上缺，巽下斷。
五行相生：金生水，水生木，木生火，火生土，土生金。
五行相剋：金克木，木克土，土克水，水克火，火克金。
");
		set("value", 20);
        	set_weight(10);
		set("material", "paper");
		set("skill", ([
			"name":	"qimen-wuxing",	// name of the skill
			"exp_required":	100,	// minimum combat experience required
			"jing_cost":	20,	// jing cost every time study this
			"difficulty":	25,	// the base int to learn this skill
			"min_skill":	20,	// the minimum level you need before study
			"max_skill":	50	// the maximum level you can learn
		]) );
        }
        setup();
}

