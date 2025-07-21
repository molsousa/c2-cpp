#ifndef VETOR_H
#define VETOR_H

#include <iostream>
#include <stdexcept>
#include <string>

/**
 * @file Vetor.h
 * @brief Defini��o da classe template Vetor.
 *
 * Esta classe implementa um vetor din�mico de tamanho fixo (at� 100 elementos)
 * capaz de armazenar qualquer tipo de dado (T). Ela oferece funcionalidades
 * b�sicas como adi��o de elementos, acesso por �ndice, sobrecarga de operadores
 * para manipula��o e m�todos para obter o tamanho.
 */

/**
 * @brief Classe template para um vetor gen�rico.
 * @tparam T O tipo de dado dos elementos a serem armazenados no vetor.
 *
 * O Vetor armazena at� 100 elementos do tipo T.
 */
template <typename T>
class Vetor {
private:
    T elementos[100]; ///< Array interno para armazenar os elementos.
    int quantidade;   ///< Quantidade de elementos atualmente no vetor.

public:
    /**
     * @brief Construtor padr�o.
     *
     * Inicializa um vetor vazio.
     */
    Vetor() : quantidade(0) {}

    /**
     * @brief Construtor de c�pia.
     * @param outroVetor O vetor a ser copiado.
     *
     * Inicializa um novo vetor com os elementos de outro vetor.
     * Copia at� o limite de 100 elementos.
     */
    Vetor(const Vetor<T>& outroVetor) : quantidade(0)
    {
        int i;
        int total_elementos = outroVetor.quantidade < 100 ? outroVetor.quantidade : 100;
        for(i = 0; i < total_elementos; ++i)
            elementos[i] = outroVetor.elementos[i];

        quantidade = total_elementos;
    }

    /**
     * @brief Adiciona um elemento em uma posi��o espec�fica do vetor.
     * @param index O �ndice onde o elemento ser� adicionado.
     * @param valor O valor a ser adicionado.
     * @throws std::out_of_range Se o �ndice estiver fora dos limites v�lidos
     * (0 a quantidade atual) ou se o vetor estiver cheio.
     *
     * Se o �ndice for igual � quantidade atual de elementos, o elemento �
     * adicionado ao final. Caso contr�rio, os elementos existentes a partir
     * do �ndice s�o deslocados para a direita.
     */
    void add(int index, T valor)
    {
        if(quantidade >= 100)
            throw std::out_of_range("Erro: Vetor cheio. Nao e possivel adicionar mais elementos.");

        if(index < 0 || index > quantidade)
            throw std::out_of_range("Erro: Indice fora dos limites para adicao.");

        int i;

        // Desloca elementos para a direita se estiver inserindo no meio
        for(i = quantidade; i > index; --i)
            elementos[i] = elementos[i - 1];

        elementos[index] = valor;
        quantidade++;
    }

    /**
     * @brief Sobrecarga do operador []. Permite acesso a elementos por �ndice.
     * @param index O �ndice do elemento a ser acessado.
     * @return Uma refer�ncia ao elemento na posi��o especificada.
     * @throws std::out_of_range Se o �ndice estiver fora dos limites v�lidos (0 a quantidade-1).
     *
     * Permite ler e atualizar o conte�do do vetor. Ex: `meuVetor[0] = valor;` ou `valor = meuVetor[0];`
     */
    T& operator[](int index)
    {
        if (index < 0 || index >= quantidade)
            throw std::out_of_range("Erro: Indice fora dos limites para acesso.");

        return elementos[index];
    }

    /**
     * @brief Sobrecarga do operador [] (vers�o const). Permite acesso de leitura a elementos por �ndice.
     * @param index O �ndice do elemento a ser acessado.
     * @return Uma refer�ncia constante ao elemento na posi��o especificada.
     * @throws std::out_of_range Se o �ndice estiver fora dos limites v�lidos (0 a quantidade-1).
     *
     * Usada quando o objeto Vetor � constante.
     */
    const T& operator[](int index) const
    {
        if (index < 0 || index >= quantidade) {
            throw std::out_of_range("Erro: Indice fora dos limites para acesso.");
        }
        return elementos[index];
    }

    /**
     * @brief Sobrecarga do operador +=. Adiciona um elemento ao final do vetor (append).
     * @param valor O valor a ser adicionado.
     * @return Uma refer�ncia para o pr�prio Vetor (para permitir encadeamento).
     * @throws std::out_of_range Se o vetor estiver cheio.
     *
     * Equivalente a `add(quantidade, valor)`.
     */
    Vetor<T>& operator+=(T valor)
    {
        add(quantidade, valor); // Usa o m�todo add para inserir no final
        return *this;
    }

    /**
     * @brief Sobrecarga do operador = (atribui��o).
     * @param outroVetor O vetor a ser atribu�do.
     * @return Uma refer�ncia para o pr�prio Vetor (para permitir encadeamento).
     *
     * Atribui os elementos de outro vetor a este vetor, sobrescrevendo os existentes.
     * Respeita o limite de 100 elementos.
     */
    Vetor<T>& operator=(const Vetor<T>& outroVetor)
    {
        if (this != &outroVetor) { // Evita auto-atribui��o
            quantidade = 0; // Reseta a quantidade atual
            int total_elementos = outroVetor.quantidade < 100 ? outroVetor.quantidade : 100;
            int i;
            for(i = 0; i < total_elementos; ++i) {
                elementos[i] = outroVetor.elementos[i];
            }
            quantidade = total_elementos;
        }
        return *this;
    }

    /**
     * @brief Retorna o elemento na i-�sima posi��o.
     * @param i O �ndice do elemento desejado.
     * @return O elemento na posi��o especificada.
     * @throws std::out_of_range Se o �ndice estiver fora dos limites v�lidos (0 a quantidade-1).
     *
     * Oferece uma maneira segura de acessar elementos, lan�ando exce��o em caso de �ndice inv�lido.
     */
    T at(int i) const
    {
        if(i < 0 || i >= quantidade)
            throw std::out_of_range("Erro: Indice fora dos limites para at().");

        return elementos[i];
    }

    /**
     * @brief Retorna a quantidade de elementos adicionados ao vetor.
     * @return A quantidade atual de elementos no vetor.
     */
    int size() const
    {
        return quantidade;
    }
};

#endif // VETOR_H
