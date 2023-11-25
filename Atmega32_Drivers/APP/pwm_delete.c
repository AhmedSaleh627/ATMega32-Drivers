#include "LIB/STD_Type.h"
#include "LIB/BITMATH.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/GIE_interrupt/GIE_interface.h"
#include "MCAL/TIMER0/TIMER0_private.h"
#include "MCAL/TIMER0/TIMER0_interface.h"

#include "HAL/LCD_Driver/LCD_interface.h"
#include "LIB/Vect_table.h"
#define F_CPU 16000000UL
#include "util/delay.h"



u8 upper[8]={
	  0x1F,
	  0x00,
	  0x00,
	  0x00,
	  0x00,
	  0x00,
	  0x00,
	  0x00
};
u8 stand_r[8]={
	     0x03,
	     0x02,
	     0x02,
	     0x1E,
	     0x00,
	     0x00,
	     0x00,
	     0x00
};
u8 stand_l[8]={
	    0x18,
	    0x08,
	    0x08,
	    0x0F,
	    0x00,
	    0x00,
	    0x00,
	    0x00
};


u8 a=0;
u8 b=1;
u8 c=2;

u8 a_20=0;
u8 b_20=1;
u8 c_20=2;
u8 d_20=3;

u8 a_30=0;
u8 b_30=1;
u8 c_30=2;
u8 d_30=3;
u8 e_30=4;



u8 a_40=0;
u8 b_40=1;
u8 c_40=2;
u8 d_40=3;
u8 e_40=4;
u8 f_40=5;



u8 a_50=0;
u8 b_50=1;
u8 c_50=2;
u8 d_50=3;
u8 e_50=4;
u8 f_50=5;
u8 g_50=6;


u8 a_60=0;
u8 b_60=1;
u8 c_60=2;
u8 d_60=3;
u8 e_60=4;
u8 f_60=5;
u8 g_60=6;
u8 h_60=7;

u8 a_70=0;
u8 b_70=1;
u8 c_70=2;
u8 d_70=3;
u8 e_70=4;
u8 f_70=5;
u8 g_70=6;
u8 h_70=7;
u8 i_70=8;

u8 a_80=0;
u8 b_80=1;
u8 c_80=2;
u8 d_80=3;
u8 e_80=4;
u8 f_80=5;
u8 g_80=6;
u8 h_80=7;
u8 i_80=8;
u8 j_80=9;


u8 a_90=0;
u8 b_90=1;
u8 c_90=2;
u8 d_90=3;
u8 e_90=4;
u8 f_90=5;
u8 g_90=6;
u8 h_90=7;
u8 i_90=8;
u8 j_90=9;
u8 k_90=10;

void dutycycle_0()
{
	LCD_Vid_GOTOXY(0,0);
	LCD_Send_String("----------------");
}
void dutycycle_10()
{
	LCD_Vid_GOTOXY(0,0);
	LCD_Send_String("----------------");
	
	LCD_Vid_Draw_data(0,stand_r,a,0);
	LCD_Vid_Draw_data(2,upper,b,0);
	LCD_Vid_Draw_data(1,stand_l,c,0);
	
	b++;
	a++;
	c++;
	if( c==15)
	{
		 a=0;
		 b=1;
		 c=2;
	}
	_delay_ms(150);
	


}
void dutycycle_20()
{
	LCD_Vid_GOTOXY(0,0);
	LCD_Send_String("----------------");
	
	LCD_Vid_Draw_data(0,stand_r,a_20,0);
	LCD_Vid_Draw_data(2,upper,b_20,0);
	LCD_Vid_Draw_data(2,upper,c_20,0);
	LCD_Vid_Draw_data(1,stand_l,d_20,0);
	
	
	a_20++;
	b_20++;
	c_20++;
	d_20++;
	if(a_20==15 || b_20==15 || c_20==15 || d_20==15)
	{
		
		a_20=0;
		b_20=1;
		c_20=2;
		d_20=3;
		
		
	}
	_delay_ms(150);
	

}

void dutycycle_30()
{
	LCD_Vid_GOTOXY(0,0);
	LCD_Send_String("----------------");
	
	LCD_Vid_Draw_data(0,stand_r,a_30,0);
	LCD_Vid_Draw_data(2,upper,b_30,0);
	LCD_Vid_Draw_data(2,upper,c_30,0);
	LCD_Vid_Draw_data(2,upper,d_30,0);
	LCD_Vid_Draw_data(1,stand_l,e_30,0);
	
	
	a_30++;
	b_30++;
	c_30++;
	d_30++;
	e_30++;
	
	
	if(a_30==15 )
	{

	
		
		a_30=0;
		b_30=1;
		c_30=2;
		d_30=3;
		e_30=4;
	
		
	}

	
	
	_delay_ms(300);
}
void dutycycle_40()
{
	LCD_Vid_GOTOXY(0,0);
	LCD_Send_String("----------------");
	
	LCD_Vid_Draw_data(0,stand_r,a_40,0);
	LCD_Vid_Draw_data(2,upper,b_40,0);
	LCD_Vid_Draw_data(2,upper,c_40,0);
	LCD_Vid_Draw_data(2,upper,d_40,0);
	LCD_Vid_Draw_data(2,upper,e_40,0);
	LCD_Vid_Draw_data(1,stand_l,f_40,0);
	
	
	a_40++;
	b_40++;
	c_40++;
	d_40++;
	e_40++;
	f_40++;
	if(f_40==15)
	{
		
	 a_40=0;
	 b_40=1;
	 c_40=2;
	 d_40=3;
	 e_40=4;
	 f_40=5;

		
		
	}
	_delay_ms(150);
}
void dutycycle_50()
{
	LCD_Vid_GOTOXY(0,0);
	LCD_Send_String("----------------");
	
	LCD_Vid_Draw_data(0,stand_r,a_50,0);
	LCD_Vid_Draw_data(2,upper,b_50,0);
	LCD_Vid_Draw_data(2,upper,c_50,0);
	LCD_Vid_Draw_data(2,upper,d_50,0);
	LCD_Vid_Draw_data(2,upper,e_50,0);
	LCD_Vid_Draw_data(2,upper,f_50,0);
	LCD_Vid_Draw_data(1,stand_l,g_50,0);
	
	a_50++;
	b_50++;
	c_50++;
	d_50++;
	e_50++;
	f_50++;
	g_50++;
	
	
	
	if(g_50==15)
	{
		
		a_50=0;
		b_50=1;
		c_50=2;
		d_50=3;
		e_50=4;
		f_50=5;
		g_50=6;

		
		
	}
	_delay_ms(150);
	
	
	
	
	
}
void dutycycle_60()
{
	LCD_Vid_GOTOXY(0,0);
	LCD_Send_String("----------------");
	
	LCD_Vid_Draw_data(0,stand_r,a_60,0);
	LCD_Vid_Draw_data(2,upper,b_60,0);
	LCD_Vid_Draw_data(2,upper,c_60,0);
	LCD_Vid_Draw_data(2,upper,d_60,0);
	LCD_Vid_Draw_data(2,upper,e_60,0);
	LCD_Vid_Draw_data(2,upper,f_60,0);
	LCD_Vid_Draw_data(2,upper,g_60,0);
	LCD_Vid_Draw_data(1,stand_l,h_60,0);
	
	a_60++;
	b_60++;
	c_60++;
	d_60++;
	e_60++;
	f_60++;
	g_60++;
	h_60++;
	
	
	
	if(h_60==15)
	{
		
		a_60=0;
		b_60=1;
		c_60=2;
		d_60=3;
		e_60=4;
		f_60=5;
		g_60=6;
		h_60=7;

		
		
	}
	_delay_ms(150);
	
}
void dutycycle_70()
{
	LCD_Vid_GOTOXY(0,0);
	LCD_Send_String("----------------");
	
	LCD_Vid_Draw_data(0,stand_r,a_70,0);
	LCD_Vid_Draw_data(2,upper,b_70,0);
	LCD_Vid_Draw_data(2,upper,c_70,0);
	LCD_Vid_Draw_data(2,upper,d_70,0);
	LCD_Vid_Draw_data(2,upper,e_70,0);
	LCD_Vid_Draw_data(2,upper,f_70,0);
	LCD_Vid_Draw_data(2,upper,g_70,0);
	LCD_Vid_Draw_data(2,upper,h_70,0);
	LCD_Vid_Draw_data(1,stand_l,i_70,0);
	
	a_70++;
	b_70++;
	c_70++;
	d_70++;
	e_70++;
	f_70++;
	g_70++;
	h_70++;
	i_70++;
	
	
	if(i_70==15)
	{
		
		a_70=0;
		b_70=1;
		c_70=2;
		d_70=3;
		e_70=4;
		f_70=5;
		g_70=6;
		h_70=7;
		i_70=8;

		
		
	}
	_delay_ms(150);
}
void dutycycle_80()
{
	LCD_Vid_GOTOXY(0,0);
	LCD_Send_String("----------------");
	
	LCD_Vid_Draw_data(0,stand_r,a_80,0);
	LCD_Vid_Draw_data(2,upper,b_80,0);
	LCD_Vid_Draw_data(2,upper,c_80,0);
	LCD_Vid_Draw_data(2,upper,d_80,0);
	LCD_Vid_Draw_data(2,upper,e_80,0);
	LCD_Vid_Draw_data(2,upper,f_80,0);
	LCD_Vid_Draw_data(2,upper,g_80,0);
	LCD_Vid_Draw_data(2,upper,h_80,0);
	LCD_Vid_Draw_data(2,upper,i_80,0);
	LCD_Vid_Draw_data(1,stand_l,j_80,0);
	
	a_80++;
	b_80++;
	c_80++;
	d_80++;
	e_80++;
	f_80++;
	g_80++;
	h_80++;
	i_80++;
	j_80++;
	
	
	if(j_80==15)
	{
		
		a_80=0;
		b_80=1;
		c_80=2;
		d_80=3;
		e_80=4;
		f_80=5;
		g_80=6;
		h_80=7;
		i_80=8;
		j_80=9;
		
		
	}
	_delay_ms(150);
}
void dutycycle_90()
{
	LCD_Vid_GOTOXY(0,0);
	LCD_Send_String("----------------");
	
	LCD_Vid_Draw_data(0,stand_r,a_90,0);
	LCD_Vid_Draw_data(2,upper,b_90,0);
	LCD_Vid_Draw_data(2,upper,c_90,0);
	LCD_Vid_Draw_data(2,upper,d_90,0);
	LCD_Vid_Draw_data(2,upper,e_90,0);
	LCD_Vid_Draw_data(2,upper,f_90,0);
	LCD_Vid_Draw_data(2,upper,g_90,0);
	LCD_Vid_Draw_data(2,upper,h_90,0);
	LCD_Vid_Draw_data(2,upper,i_90,0);
	LCD_Vid_Draw_data(2,upper,j_90,0);
	LCD_Vid_Draw_data(1,stand_l,k_90,0);
	
	a_90++;
	b_90++;
	c_90++;
	d_90++;
	e_90++;
	f_90++;
	g_90++;
	h_90++;
	i_90++;
	j_90++;
	k_90++;
	
	if(k_90==15)
	{
		
		a_90=0;
		b_90=1;
		c_90=2;
		d_90=3;
		e_90=4;
		f_90=5;
		g_90=6;
		h_90=7;
		i_90=8;
		j_90=9;
		k_90=10;
		
		
	}
	_delay_ms(150);
}
void dutycycle_100()
{
	LCD_Vid_Draw_data(2,upper,0,0);
	LCD_Vid_Draw_data(2,upper,1,0);
	LCD_Vid_Draw_data(2,upper,2,0);
	LCD_Vid_Draw_data(2,upper,3,0);
	LCD_Vid_Draw_data(2,upper,4,0);
	LCD_Vid_Draw_data(2,upper,5,0);
	LCD_Vid_Draw_data(2,upper,6,0);
	LCD_Vid_Draw_data(2,upper,7,0);
	LCD_Vid_Draw_data(2,upper,8,0);
	LCD_Vid_Draw_data(2,upper,9,0);
	LCD_Vid_Draw_data(2,upper,10,0);
	LCD_Vid_Draw_data(2,upper,11,0);
	LCD_Vid_Draw_data(2,upper,12,0);
	LCD_Vid_Draw_data(2,upper,13,0);
	LCD_Vid_Draw_data(2,upper,14,0);
	LCD_Vid_Draw_data(2,upper,15,0);
	
}
u8 dutycyle_counter=0;
int main(void)
{
	
	EXT_Vid_Interrupt_Init() ;
	DIO_Vid_Set_Pin_Dir(PORTD,PIN0,OUTPUT);
	DIO_Vid_Set_Pin_Dir(PORTB,PIN3,OUTPUT);
	
	DIO_Vid_Set_Pin_Dir(PORTD,PIN2,INPUT);
	DIO_Vid_Set_Pin_Dir(PORTD,PIN3,INPUT);
	LCD_Vid_Init();
	LCD_Vid_GOTOXY(0,1);
	LCD_Send_String("DutyCycle= ");
	
	dutycycle_0();

	while(1)
	{
		EXT_Vid_Interrupt0() ;
		EXT_Vid_Interrupt1() ;
		
	
	
		if(dutycyle_counter>=246 )
		{
			dutycyle_counter=0;
			LCD_Vid_GOTOXY(11,1);
			LCD_Vid_Send_Data(' ');
			LCD_Vid_Send_Data(' ');
		}
		if(dutycyle_counter>=110)
		{
			dutycyle_counter=100;
		
		}
		if(dutycyle_counter==90)
		{
			LCD_Vid_GOTOXY(12,1);
			LCD_Vid_Send_Data(' ');
			
		}
		if(dutycyle_counter==0)
		{
			LCD_Vid_GOTOXY(11,1);
			LCD_Vid_Send_Data(' ');
			
		}
		LCD_Vid_GOTOXY(10,1);
		
		LCD_Send_Number(dutycyle_counter);

		Timer0_Vid_Fast_PWM(dutycyle_counter);
		
		if(dutycyle_counter==10)
		{
			dutycycle_10();
		}
		if(dutycyle_counter==20)
		{
			dutycycle_20();
		}
		if(dutycyle_counter==30)
		{
			
			dutycycle_30();
		}
		
		if(dutycyle_counter==40)
		{
			
			dutycycle_40();
		}
		if(dutycyle_counter==50)
		{
			
			dutycycle_50();
		}
		if(dutycyle_counter==60)
		{
			
			dutycycle_60();
		}
		if(dutycyle_counter==70)
		{
			
			dutycycle_70();
		}
		if(dutycyle_counter==80)
		{
			
			dutycycle_80();
		}
		if(dutycyle_counter==90)
		{
			
			dutycycle_90();
		}
		
		if(dutycyle_counter==100)
		{
			
			dutycycle_100();
		}
	}
	
	
}

ISR(INT_0)
{
	
	dutycyle_counter+=10;
	
}
ISR(INT_1)
{

	dutycyle_counter-=10;
	
}
