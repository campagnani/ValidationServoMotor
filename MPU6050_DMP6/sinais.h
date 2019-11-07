void executaDegraus(int amplitude, double frequenciaMin, double frequenciaPasso, double frequenciaMax, double taxaDeAmostragem)
{
  double w = 0;
  for (double frequencia = frequenciaMax; frequencia >= frequenciaMin; frequencia -= frequenciaPasso)
  {
    for (double t = 0; t < (1 / frequencia) ; t += taxaDeAmostragem)
    {
      if (amplitude * sin(pi * frequencia * t) >= 0)
      {
        servo.write(amplitude);
        Serial.print(leiaAngulo());
        Serial.print("\t");
        Serial.print(amplitude);
        Serial.println(";");

      }
      else
      {
        servo.write(-amplitude);
        Serial.print(leiaAngulo());
        Serial.print("\t");
        Serial.print(-amplitude);
        Serial.println(";");
      }
      float tempo = k * taxaDeAmostragem;
      k += 1;
    }
    w += (1 / frequencia);
  }
}

void executaSinVar(int amplitude, double frequenciaMin, double frequenciaPasso, double frequenciaMax, double taxaDeAmostragem)
{

  double w = 0;
  for (double frequencia = frequenciaMax; frequencia >= frequenciaMin; frequencia -= frequenciaPasso)
  {
    for (double t = 0; t < (1 / frequencia) ; t += taxaDeAmostragem)
    {
      int angulo = amplitude * sin(pi * frequencia * t);
      servo.write(angulo);
      Serial.print(leiaAngulo());
      Serial.print("\t");
      Serial.print(angulo);
      Serial.println(";");
      k += 1;
    }
    w += (1 / frequencia);
  }
}
