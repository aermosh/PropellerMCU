clear all
close all
set(0, 'DefaultLineLineWidth', 2);

dat = csvread('adc_measurements_01-05-2018-1.csv');
Nplots = 2;
voltage = dat(:,1);

for j = 1:Nplots
    
    reading = dat(:,j+1:j+10);
    avg_reading = mean(reading, 2);
    % plot readings from power supply
    min_read = min(avg_reading);
    max_read = max(avg_reading);

    reading_adj_avg = 4096*(avg_reading-min_read)/(max_read-min_read);
    voltage_adj = voltage/3.3;
    
    figure;
    subplot(2,1,1)
    plot(voltage_adj, reading_adj_avg, '-o');
    hold on
    plot([0, 1], [0,4096]);
    axis square
    for i = 1:10
        scatter(voltage_adj, 4096*(reading(:,i)-min_read)/(max_read-min_read));
    end

    xlabel('Voltage [scaled]');
    ylabel('ADC Value [scaled]');
    title('ADC Value vs Input Voltage');

    subplot(2,1,2);
    codes = linspace(0,4095,34).';
    inl = (reading_adj_avg-codes);
    plot(codes, inl, '-o')
    axis square
    xlabel('Code');
    ylabel('INL');
    title('INL vs Code');
    
    enob = 12-log2(max(abs(inl)));
end