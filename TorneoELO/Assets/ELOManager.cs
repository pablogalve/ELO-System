using UnityEngine;
using System.Collections.Generic;

public class ELOManager : MonoBehaviour {

    public string Username { get; set; }
    public float ELO { get; set; }
    public float min { get; set; } //minutos de uso

    int Round;

    float AvgUp = 0;  //Los mejores que tú
    float AvgDown = 0;  //Los peores que tú
    float ProbWinUp = 0;  //Probabilidad de ganar a los que te han ganado
    float ProbWinDown = 0;  //Probabilidad de ganar a los que has ganado
    float WinELO = 0; //Puntos que ganará
    float LoseELO = 0; //Puntos que perderá
    float k; //Constante k. Es el número máximo de puntos que puede ganar/perder un jugador en una partida
    int userUp = 0; //Los usuarios que hay por delante tuya en el ranking
    int userDown = 0; //Los usuarios que hay por debajo tuya en el ranking


    public float timer;
    List<ELOManager> Ranking = new List<ELOManager>();
    List<float> winELOList = new List<float>();
    List<float> loseELOList = new List<float>();

    public ELOManager(string Username, float ELO, float min)
    {
        this.Username = Username;
        this.ELO = ELO;
        this.min = min;
    }
    void Init()
    {
        if(Ranking == null)
        {
           Ranking = new List<ELOManager>();
        }
        if(winELOList == null)
        {
            winELOList = new List<float>();
        }
        if (loseELOList == null)
        {
            loseELOList = new List<float>();
        }
    }

	void Start () {
        Init();       

        var user1 = new ELOManager("AAAAAAA", 1000, 1);
        var user2 = new ELOManager("BBBBBBB", 1000, Random.Range(50, 100));
        var user3 = new ELOManager("User3", 1000, Random.Range(50, 100));
        var user4 = new ELOManager("User4", 1000, Random.Range(50, 100));
        var user5 = new ELOManager("User5", 1000, Random.Range(50, 100));
        var user6 = new ELOManager("User6", 1000, Random.Range(50, 100));
        var user7 = new ELOManager("User7", 1000, Random.Range(50, 100));
        var user8 = new ELOManager("User8", 1000, Random.Range(50, 100));
        var user9 = new ELOManager("User9", 1000, Random.Range(50, 100));
        var user10 = new ELOManager("User10", 1000, 9999);

        Ranking.Add(user1);
        Ranking.Add(user2);
        Ranking.Add(user3);
        Ranking.Add(user4);
        Ranking.Add(user5);
        Ranking.Add(user6);
        Ranking.Add(user7);
        Ranking.Add(user8);
        Ranking.Add(user9);
        Ranking.Add(user10);                
    }
	
	void Update () {
        timer += Time.deltaTime;
        if (timer > 3)  //Cada 3 segundos se ejecuta el código
        {
            Round++;
            RandomTimes();
            CalculateELO();
            GiveELO();            
            timer = 0;
        }
	}

    void CalculateELO()   //Calculamos cuantos puntos ganará y perderá cada jugador
    {
        Ranking.Sort((p1, p2) => p1.min.CompareTo(p2.min)); //Ordenamos el ranking del que menos ha usado el móvil al que más lo ha usado
        print("-------------------------------------------------------------------------------- Round: " + Round);

        for (int i = 0; i < Ranking.Count; i++)  //.Count cuenta el número de usuarios que hay en "Ranking"
        {
            AvgUp = 0;  //Los mejores que tú
            AvgDown = 0;  //Los peores que tú
            ProbWinUp = 0;  //Probabilidad de ganar a los que te han ganado
            ProbWinDown = 0;  //Probabilidad de ganar a los que has ganado
            WinELO = 0; //Puntos que ganará
            LoseELO = 0; //Puntos que perderá
            k = 5; //Constante k. Es el número máximo de puntos que puede ganar/perder un jugador en una partida
            userUp = 0; //Los usuarios que hay por delante tuya en el ranking
            userDown = 0; //Los usuarios que hay por debajo tuya en el ranking

            userUp = i;  //El número de usuarios que hay encima coincide con i
            userDown = Ranking.Count - i;  //Usuarios totales - Yo

            if (i != 0)  //Si no es el primero
            {
                AvgUp = Ranking[i - 1].ELO;          //AvgUp = El ELO de la persona que hay encima de ti
                ProbWinUp = 1 / (1 + Mathf.Pow(10, (AvgUp - Ranking[i].ELO) / 400));
                LoseELO = k * (0 - ProbWinUp) * userUp;
            }
            else if(i == 0) //Si eres el primero
            {
                AvgUp = 0;
                LoseELO = 0;
            }
            if (i != Ranking.Count -1 ) //Si no eres el último
            {
                AvgDown = Ranking[i + 1].ELO;       //La persona que hay debajo de ti
                ProbWinDown = 1 / (1 + Mathf.Pow(10, (AvgDown - Ranking[i].ELO) / 400));
                WinELO = k * (1 - ProbWinDown) * userDown;
            }
            else if (i == Ranking.Count)  //Si eres el último
            {
                AvgDown = 0;
                WinELO = 0;
            }
            

            if (Ranking[i].ELO <= 400) //Si algún usuario tiene muy pocos puntos, le añadimos puntos extras para evitar que lleguen a ser un número negativo
            {
                WinELO += 10;
            }
            else if (Ranking[i].ELO <= 200)
            {
                WinELO += 30;
            }
            else if (Ranking[i].ELO <= 100)
            {
                WinELO += 50;
            }
            winELOList.Add(WinELO);
            loseELOList.Add(LoseELO);
            

            print(Ranking[i].Username + " ELO:" + Ranking[i].ELO + " Min:" + Ranking[i].min + " AvgUp: " + AvgUp + " AvgDown: " + AvgDown + " ProbUp: " + ProbWinUp + " ProbDown: " + ProbWinDown + " WinELO: " + WinELO + " LoseELO: " + LoseELO);            
        }
    }

    void GiveELO()    //Distribuimos los puntos que hemos calculado en la función CalculateELO()
    {
        for(int i = 0; i < Ranking.Count; i++)
        {
            Ranking[i].ELO += winELOList[i];
            Ranking[i].ELO += loseELOList[i];
        }
    }
    void RandomTimes()  //Añadimos tiempo de uso aleatorio para poder hacer las pruebas
    {
        for(int i = 0; i<Ranking.Count; i++)
        {
            Ranking[i].min = Random.Range(10, 500);
        }
    }
}
